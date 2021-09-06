// reg.c
// created by campsun 2004.2.9
// Modified by Ciwei@SJ


inherit F_CLEAN_UP;

#include <ansi.h>
#include <database.h>
#include <mudlib.h>

object get_player(string arg);

nosave object author;

int main(object me, string arg)
{
	object ob;
	int vip_day;
	int now_time;
	int vip_time;
	int flag = 0;

	now_time = time();
	
	if( me!=this_player(1) ) return 0;
	
	author=me;
	
	if( !arg || sscanf(arg, "%s %d", arg, vip_day)!=2 )
		return notify_fail("ָ���ʽ��regvip <�û�ID> <����>\n");

    	if (!objectp(ob = LOGIN_D->find_body(arg))){
    		flag = 1;
		if(!objectp(ob = get_player(arg))) return notify_fail("û������˰�?\n");
	}
        
        //if(!objectp(environment(ob)))
                  //return notify_fail("����˲�֪����������Ү... :-( \n");//�������Ҫ��

	/*if(ob->query("registered")!=3)
		return notify_fail("�Է����ǹ���û��������趨���������\n");*/
	
	
	if((int)ob->query("vip/vip_time")!=0 && (int)ob->query("vip/vip_time") < now_time)
	{
		ob->delete("vip/vip_time");
		ob->delete("vip/vip_start_time");
		return notify_fail("�Է��Ĺ���Ѿ����ڣ���ǽ���ɾ���������³�ֵ��\n");
	}
	
	vip_time = vip_day * 24 * 3600;
	
	if(vip_time==0) return notify_fail("�������ֻ���ͳ��Լ����������Ѷ�Ŷ��\n");
		
	if (!(int)ob->query("vip/vip_start_time"))
	{
		if(vip_time<0)
		{
			return notify_fail("�Է�����VIP�û�������Ҫ���м���VIP��Ч�ڵĲ�����\n");
		}
		ob->set("vip/vip_time",vip_time + now_time);
		ob->set("vip/vip_start_time",now_time);	
		if(!ob->save()) return notify_fail("������ݱ���ʧ�ܣ�ע����Ч\n");
		//save ʧ�� ����log
		//message_vision("$NΪ$n��ͨ�� " +HIY+ vip_day +NOR+ " ��Ĺ������ʹ�� time ������в鿴��\n", me, );
		tell_object(me,"��Ϊ"+ob->name()+"��ͨ�� " +HIY+ vip_day +NOR+ " ��Ĺ����\n");
		tell_object(ob,me->name()+"Ϊ�㿪ͨ�� " +HIY+ vip_day +NOR+ " ��Ĺ������ʹ�� time ������в鿴��\n");
		log_file( "static/VIP", me->query("name")+"("+me->query("id")+") �� " +
			ob->query("name") + "(" + ob->query("id") + ") ��ͨ�� " + vip_day + " ������\n" );
	}
	else
	{
		//vipid  username  regemail  regtimelimit  updatetime  
		//    1 aboy@ln2 xhy009@shujian.com 1087012108 1081396108 
		string dex="����";
		if(vip_time<0) dex="����";
				
		//if(vip_time>0) return notify_fail("��ʱ��ֹ����Vip Time�Ĳ�����\n");
						
		ob->add("vip/vip_time",vip_time);
		ob->set("vip/vip_start_time",now_time);
		if(!ob->save()) return notify_fail("������ݱ���ʧ�ܣ�ע����Ч\n");
		//message_vision("$NΪ$n������ " + HIY + vip_day + NOR + " ��Ĺ������ʹ�� time ������в鿴��\n", me, ob);
		
		if(!BBS_D->add_Bbs_Up_Map(WEB_DB_NAME,
		"UPDATE mudvips SET regtimelimit = regtimelimit+'"+vip_time+"' WHERE username = '"+getuid(ob)+"@"+lower_case(INTERMUD_MUD_NAME)+"' limit 1",
		this_object(),"back"));
		
		tell_object(me,"��Ϊ"+ob->name()+dex+"�� " +HIY+ ABS(vip_day) +NOR+ " ��Ĺ����\n");
		//tell_object(ob,me->name()+"Ϊ�������� " +HIY+ ABS(vip_day) +NOR+ " ��Ĺ������ʹ�� time ������в鿴��\n");
		log_file( "static/VIP", me->query("name")+"("+me->query("id")+") �� " +
			ob->query("name") + "(" + ob->query("id") + ") "+dex+"�� " + ABS(vip_day) + " ������\n" );
	}
	if(flag==1) destruct(ob);
	flag = 0;
	return 1;
}

void back()
{
	tell_object(author,"Web���ݿ������ɡ�\n");
}

object get_player(string arg)
{
	object user;	
	
	user = new(USER_OB);
	if (!user) {
		write("���ڿ������������޸�ʹ��������ĳ����޷����и��ơ�\n\n");
		return 0;
	}
	seteuid(arg);
	export_uid(user);
	seteuid(getuid());
	if(!user->restore()) {
	destruct(user);
	return 0;}
	user->set_name(user->query("name"), ({ arg}));
	return user;
}

int help(object me)
{
	write(@HELP
ָ���ʽ�� regvip ����<id> ����<day>

����������趨vip������
HELP );
    return 1;
}
