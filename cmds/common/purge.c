// purge.c
// modify by looklove 2001.7.4

inherit F_CLEAN_UP;

#include <ansi.h>
#include <mudlib.h>

private int do_purge_players(int day);
int help(object me);

int main(object me, string arg)
{
	string name, reason, msg;
	int day;

	if (me!=this_player(1) || wiz_level(me) < wiz_level("(arch)")||wiz_level(me) < wiz_level(name))
		return notify_fail("��û��Ȩ��ʹ�����ָ�\n");

	if( !arg ) return help(me);

        if( sscanf(arg, "%d", day) && day >= 15 && day <= 10000) return do_purge_players(day);

	if( sscanf(arg, "%s because %s", name, reason)==2 ){
		seteuid(getuid());
		if( file_size(DATA_DIR + "login/" + name[0..0] + "/" + name + SAVE_EXTENSION)<0 )
			return notify_fail("û����λʹ���ߡ�\n");
		"/cmds/wiz/kickout"->main(me, name);

		msg =   ""+name+ "�����ã�\n"+
			"    �������ؿ��ǣ����Ǻ��ź���֪ͨ��������"+CHINESE_MUD_NAME+"��ID�Ѿ���ϵͳɾ����\n"+
			"ɾ��ԭ���ǡ�"+reason+"���������׼��������¼�齣��Ϸ������������ID��ʼ��Ϸ��\n"+
			"��������ע�������齣��Ϸ�����������ڽ�����Ϸ���á�help rules��ָ��鿴��\n"+
			"\n"+
			"����\n"+
			"				�齣��ʦ��\n"+
			"\n"+ctime(time());

		SMTP_D->send_mail(me,name,"֪ͨ�ʼ�",msg);

                shout(HIR"���齣ͨ�桿"+capitalize(name)+"��Ϊ�� "+reason+" ������ʧ����������ˡ�\n"NOR);
                write(HIR"���齣ͨ�桿"+capitalize(name)+"��Ϊ�� "+reason+" ������ʧ����������ˡ�\n"NOR);

		// rm s -f ���ݣ���ֹ�����б����� s -f ��ID�� recovers
		rm(DATA_DIR + "login/" + name[0..0] + "/" + name + ".ooo");
		rm(DATA_DIR + "user/" + name[0..0] + "/" + name + ".ooo");
		// ͬʱɾ�����ݿ��������
		if (dbquery("DELETE FROM Users "
			"where U_Username='" + name + "'"))
			tell_object(me,HIY"���ݿ�Users����������Ѿ��ɹ�ɾ����\n"NOR);	
		else
		{
			tell_object(me,HIY"���ݿ�UserS���������ɾ��ʧ�ܣ�����LinuX��ϵ��\n"NOR);
			log_file("static/PURGE",sprintf("%s ɾ�� %s Users���������ʧ��!\n",
				geteuid(this_player(1)), name
			), this_player(1), ({ name })
		);	
		}		
                if (dbquery("DELETE FROM Data WHERE U_ID='" 
                        + DATA_DIR + "login/" + name[0..0] + "/" + name + ".o"+"'"))
                	tell_object(me,HIY"���ݿ�Data�����Login�����Ѿ��ɹ�ɾ����\n"NOR);	
		else
		{	
			tell_object(me,HIY"���ݿ�Data�����Login����ɾ��ʧ�ܣ�����LinuX��ϵ��\n"NOR);
			log_file("static/PURGE",sprintf("%s ɾ�� %s Data�����Login����ʧ��!\n",
				geteuid(this_player(1)), name
			), this_player(1), ({ name })
		);	
		}
                
                if (dbquery("DELETE FROM Data WHERE U_ID='" 
                        + DATA_DIR + "user/" + name[0..0] + "/" + name + ".o"+"'"))
                	tell_object(me,HIY"���ݿ�Data�����User�����Ѿ��ɹ�ɾ����\n"NOR);	
		else
		{
			tell_object(me,HIY"���ݿ�Data�����User����ɾ��ʧ�ܣ�����LinuX��ϵ��\n"NOR);
			log_file("static/PURGE",sprintf("%s ɾ�� %s Data�����User����ʧ��!\n",
				geteuid(this_player(1)), name
			), this_player(1), ({ name })
		);	
		}
		
		rename(DATA_DIR + "login/" + name[0..0] + "/" + name + SAVE_EXTENSION,
			DATA_DIR + "login/" + name[0..0] + "/" + name + ".ppp");
		rename(DATA_DIR + "user/" + name[0..0] + "/" + name + SAVE_EXTENSION,
			DATA_DIR + "user/" + name[0..0] + "/" + name + ".ppp");

		log_file("static/PURGE",
			sprintf("%s purged %s because %s\n",
				geteuid(this_player(1)), name, reason
			), this_player(1), ({ name })
		);

		return 1;
	}
	return help(me);
}

private int do_purge_players(int day)
{
	int i, j, k, ppl_cnt = 0, count = 0, t = time() - 86400 * day, login = 0, user = 0;
	string *dir, name, *tmp;
	mixed *info;

	seteuid(getuid());
	message("system", "\n*** ������Ҵ��浵�У����Ժ�.... ***\n", users());
	write("�����¼�����У�");
	dir = get_dir(DATA_DIR + "login/");
	for(i=0; i<sizeof(dir); i++) {
		if (file_size(DATA_DIR + "login/" + dir[i]) != -2) continue;
		reset_eval_cost();
		write(dir[i]);
		flush_messages();
		info = get_dir(DATA_DIR + "login/" + dir[i] + "/", -1);
		tmp = get_dir(DATA_DIR + "user/" + dir[i] + "/");
		j = sizeof(info);
		while (j--) {
			if (!tmp || member_array(info[j][0], tmp) == -1) {
				rm(DATA_DIR + "login/" + dir[i] + "/" + info[j][0]);
				login++;
				continue;
			}
			if (sscanf(info[j][0]+"$", "%s.o$", name)==1) {
				ppl_cnt++;
				if (wizhood(name) != "(player)") continue;
				k = 1;
			} else k = 0;
			if (t > info[j][2]) {
				rm(DATA_DIR + "login/" + dir[i] + "/" + info[j][0]);
				rm(DATA_DIR + "user/" + dir[i] + "/" + info[j][0]);
				count += k;
			}
		}
	}
	write("\n�������ݵ����У�");
	dir = get_dir(DATA_DIR + "user/");
	for (i=0; i<sizeof(dir); i++) {
		if (file_size(DATA_DIR + "user/" + dir[i]) != -2) continue;
		reset_eval_cost();
		write(dir[i]);
		flush_messages();
		info = get_dir(DATA_DIR + "user/" + dir[i] + "/", -1);
		tmp = get_dir(DATA_DIR + "login/" + dir[i] + "/");
		j = sizeof(info);
		while (j--) {
			if (!tmp || member_array(info[j][0], tmp) == -1) {
				rm(DATA_DIR + "user/" + dir[i] + "/" + info[j][0]);
				user++;
				continue;
			}
			if (t > info[j][2]) {
				if (sscanf(info[j][0]+"$", "%s.o$", name)==1) {
					if (wizhood(name) != "(player)") continue;
					count++;
				}
				rm(DATA_DIR + "login/" + dir[i] + "/" + info[j][0]);
				rm(DATA_DIR + "user/" + dir[i] + "/" + info[j][0]);
			}
		}
	}
	write("\n\nԭ���ܹ��� " + ppl_cnt + " λʹ���ߡ�\n");
	write( count + " ������ " + day + " ��δ���ߵ�ʹ���߱�������ˡ�\n");
	write( login + " �������ĵ�¼������������ˡ�\n");
	write( user + " �����������ݵ�����������ˡ�\n");
	write("�����ܹ��� " + (ppl_cnt - count) + " λʹ���ߡ�\n");
	log_file("static/PURGE",
		sprintf("%s cleaned up %d characters who didn't login for more than %d days\n"
			"\t\tResulting statistics: %d characters remaining.\n",
			geteuid(this_player(1)), count, day, ppl_cnt - count
		), this_player(1)
	);

	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ��purge [<δ��������>] | <ʹ��������> because <ԭ��>

���һ��ʹ���߻��������һ�������������ߵ�ʹ���ߡ�
��ע��ɾ��ԭ��Ĵ�ǣ���Ϊϵͳ���Դ�Ϊɾ�����ɣ��Զ����ID����֪ͨ�ʼ���
HELP
);
    return 1;
}

