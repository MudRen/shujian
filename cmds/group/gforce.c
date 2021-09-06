// gforce.c ǿ��ִ��
// by augx@sj 3/25/2002

#include <ansi.h>
inherit F_CLEAN_UP;

int help(object me)
{
	write(@HELP
ָ���ʽ��
gforce [���id] do [����]
ʹ�ô�����������Լ��İ�����ǿ�ȵȼ����Լ��͵���Һ�NPCִ�����

gforce [���id] do here
ʹ�ô�����������Լ��İ���������ȼ����Լ��͵���ҵ����������ڵĵط���

gforce [����id] do save
�ѱ��ڵ�״̬���̣����ڵ�ʱ���ڵص�Ҳ���Ϊ�������ص㡣

gforce [����id] do setname [����������(�����ĸ�����)]
  [������Ӣ��ID(�����������ʣ�ÿ���ʳ���Ϊ2��6����ĸ)]
���磺gforce guard do setname ���� body guard
���ñ��ڵ������֣�ÿ������ֻ������һ�����֣����ú�����̡�

ǿ�Ʊ���ִ������ʱ�����ܲ��ܵõ������ķ�����Ϣ�����������Ϣ�ȣ���ע�⡣
HELP );
	return 1;
}


string * exclude_commands = ({
	"passwd","quit","fangqi","abandon","chat","rumor","say","reply","party","sj","irc","to","tell",
	"lian","practice","chat*","rumor*","alias","sj*","vote","team","group","group*","party*","alias","sr","sr*"
});

int main(object me, string arg)
{
	string cmd,cmds,str,ob_file,id1,id2;
	object ob,env;
	int flag;

	return notify_fail("��ʱ�رա�\n");

	if (!arg || !sscanf(arg, "%s do %s", arg, cmds)) return help(me);
	if ( !(ob = present(arg, environment(me))) ) {
		if( cmds != "here" )
			return notify_fail("û������ˡ�\n");
		else if ( !(ob=find_player(arg)) || environment(ob)->query("group1")!=me->query("group/id") )
			return notify_fail("û������˻��ߴ��˲��ڰ�������֮�ڡ�\n");
	}
	if (ob == me)
		return notify_fail("ֱ�Ӵ�����ȽϿ�Щ��\n");
	if( !me->query("group/id")
	  || me->query("group/id") != ob->query("group/id")
	  || me->query("group/class") >= ob->query("group/class") )
		return notify_fail("��ֻ������ͬ���ɣ��ҵȼ�����͵��ˡ�\n");
	if( environment(me)->query("group1") != me->query("group/id") )
		return notify_fail("��ֻ���Լ��İ�����������ˡ�\n");
	if( !GROUP_D->site_now(me->query("group/id")) )
		return notify_fail( GROUP_D->get_last_error() );

	seteuid(getuid());
	if( cmds != "here" ) message_vision("$N����$nִ�������"HIR+cmds+NOR"����\n", me,ob);

	if( sscanf(cmds,"%s %*s",cmd) < 1 ) cmd = cmds;

	flag = 0;
	switch ( cmd ) {
		case "fangqi":
		case "abandon":
			if( !userp(ob) ) {
				if( sscanf(cmds,"%*s %s",cmd) < 1 )
					return notify_fail("��Ҫ"+ob->name()+"����ʲô���ܣ�\n");
				ob->delete_skill(cmd);
				return 1;
			}
			else flag = 1;
			break;
		case "here":
			if( ob->is_busy() || ob->is_fighting() )
				return notify_fail(ob->name()+"��æ���ء�\n");

			tell_room(environment(ob),"$N�ƺ�ͻȻ������ʲô����������ææ�����˹�ȥ��\n",({ ob }));
			tell_object(ob,"���ƺ�ͻȻ����"+me->name()+"�ں����㣬��æ���˹�ȥ��\n");
			ob->move(environment(me));
			message_vision("$N��������$n�����֣�$n�������æ���˹�����\n",me,ob);
			return 1;
		case "save":
			if( !userp(ob) ) {
				if( (ob->query_temp("last_save")+15*60)>time() && !wizardp(me) )
					return notify_fail(ob->name()+"��״̬���Ǹոմ������\n");

				log_file( "group/save" , sprintf("save:%s(%s)[%d]:%s(%s)\n",ob->name(),ob->query("id"),ob->skill_count(),me->name(),me->query("id")) );

				if( ob->query("startroom") == base_name(environment(ob)) ) {
					ob->set_temp("last_save",time());
					if( !ob->save() )
						log_file("group/save",sprintf("fail:%s(%s):%s(%s)\n",ob->name(),ob->query("id"),me->name(),me->query("id")));
					tell_object(me,ob->name()+"�洢��ϡ�\n");
					return 1;
				}

				ob_file = replace_string( base_name(ob)+".c" , "/d/group/"+me->query("group/id")+"/", "" );

				if( ob->query("startroom") ) {
					if( !(env=find_object(ob->query("startroom"))) )
						env = load_object(ob->query("startroom"));
					if( env ) {
						if( !GROUP_D->create_room(
							base_name(env)+".c",
							env->query("short"),env->query("long"),
							GROUP_D->get_room_exits(env),replace_string(GROUP_D->get_room_objects(env),"__DIR__`"+ob_file+"`:1,",""),
							env->query("group1"),env->query("group2"),
							env->query("outdoors")?0:1, env->query("have_board") )
						)
							return notify_fail("д�ļ������뱨����ʦ��\n");

						GROUP_D->encrypt_file(base_name(env)+".c");
						GROUP_D->update_room(base_name(env)+".c");
					}
				}

				env = environment(ob);

				str = GROUP_D->get_room_objects(env);
				if( strsrch( str , "__DIR__`"+ob_file+"`:1," ) == -1 )
					str +=  "__DIR__`"+ob_file+"`:1,";
				if( !GROUP_D->create_room(
					base_name(env)+".c",
					env->query("short"),env->query("long"),
					GROUP_D->get_room_exits(env),str,
					env->query("group1"),env->query("group2"),
					env->query("outdoors")?0:1, env->query("have_board") )
				)
					return notify_fail("д�ļ������뱨����ʦ��\n");

				tell_object(me,ob->name()+"�洢��ϡ�\n");

				ob->set("startroom","");
				ob_file = base_name(env);

				GROUP_D->encrypt_file(base_name(env)+".c");
				GROUP_D->update_room(base_name(env)+".c");

				ob->set("startroom",ob_file);
				ob->set_temp("last_save",time());
				ob->save();

				return 1;
			}
			break;
		case "setname":
			if( userp(ob) ) break;
			if( sscanf(cmds,"%*s %s %s %s",cmd,id1,id2) < 3 )
				return notify_fail("��Ҫ��"+ob->name()+"�����ָĳ�ʲô��\n");
			if( strlen(cmd)<4 || strlen(cmd)>8 )
				return notify_fail("�����ֱ����Ƕ����ĸ����֡�\n");
			if( strlen(id1)<2 || strlen(id1)>6 || strlen(id2)<2 || strlen(id2)>6 )
				return notify_fail("��Ӣ��ID���Ȳ����Ϲ涨��\n");
			if( ob->query("setname") )
				return notify_fail(ob->name()+"�Ѿ����ù������ˡ�\n");

			ob->set("name",cmd);
			ob->set("id",id1+" "+id2);
			ob->set("id1",id1);
			ob->set("id2",id2);
			ob->set("setname",1);
			ob->set_name( ob->query("name"), ({ ob->query("id"),ob->query("id1"),ob->query("id2"),"group guard","guard" }));
			break;
		default: flag = 1;
	}
	if( flag && member_array(cmd,exclude_commands)>=0 )
		return notify_fail("����������������ֹǿ��ִ�У�\n");

	if( !ob->force_me(cmds) )
		return notify_fail("������"+ob->name()+"ִ������ʧ�ܡ�\n");
	return 1;
}
