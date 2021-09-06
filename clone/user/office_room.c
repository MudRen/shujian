// office_room.c
// Created By Numa@SJ 2001/03/02
// for solve player's problem automaticly.

/*
*** cmds help format :
string help()
{
	return sprintf(HIW"��"GRN"%|20s  "NOR"%|60s"HIW"��\n","recovers [id]","�����Զ��ָ���ɱ����ҡ�");
}

*** cmds transfer format :
string do_auto(object player, string id)
{
	...;
}
*/

#include <ansi.h>
inherit ROOM;

// define office_room's commands directory
#define DIR "/clone/user/office/"
string *file = ({});
object ob = 0;

// define the limit to player
int player_limit(object ob)
{
//	if (ob->query("age") < 20)
//		return 0;
	return 1;
}

// find all cmds
void check_cmds()
{
	object f;
	mixed *d;
	int i, fl;
	
        d = get_dir(DIR,-1);
        for (i=0;i<sizeof(d);i++) {
                if (d[i][1] == -2)
                        continue;
                fl = strlen(d[i][0]);
                if (d[i][1] <= 0
                 || d[i][0][(fl-2)..(fl-1)] != ".c")
                        continue;
    	        if (!(f = find_object(DIR+d[i][0])))
    			f = load_object(DIR+d[i][0]);
    		file += ({d[i][0][0..(fl-3)]});
        }
}

void create()
{
        set("short", HIW"�������칫��"NOR);
        set("long", "������"+MUD_NAME+"���������칫���ҡ�
���д�̨�һ���������˵Ĺ������ڵǼ���ʲô���������������Ҷ�
���д�̨�Աߵĳ����ϵȺ������ڰ칫������һ�������������˵��
(help)��\n");
        set("exits", ([
               "down" : "/d/wuguan/dayuan"
        ]));
        set("no_death", 1);
        set("no_save", 1);
	set("no_fight", 1);
        setup();
        seteuid(ROOT_UID);
        check_cmds();
}

void init()
{
        object ob = this_player();
        
        add_action("do_help","help");
	if (!player_limit(ob)) return;
	add_action("ido","ido");
}

int check_valid_player(string my_id, string id)
{
	object my_ob, ob;
	
	my_ob = new(LOGIN_OB);
	my_ob->set("id", my_id);
    	if (!my_ob->restore()) {
    		destruct(my_ob);
    		return 0;
    	}

	ob = new(LOGIN_OB);
	ob->set("id", id);
    	if (!ob->restore()) {
    		destruct(ob);
    		return 0;
    	}
//        if (ob->query("email") == my_ob->query("email")) {
        if (ob->query("password") == my_ob->query("password")) {
    		destruct(my_ob);
    		destruct(ob);
    		return 1;
    	}
  	destruct(my_ob);
    	destruct(ob);
    	return 0;
}

int ido(string arg)
{
	object me = this_player();
	object file_ob;
	string file, act, id, msg = "";
	
	if (ob)
		return notify_fail("���Եȣ�ϵͳ���ڽ��"+ob->name()+"�����⡣\n");
		
	if (!arg || sscanf(arg, "%s %s", act, id) != 2)
		return notify_fail("��Ҫ���ʲô���⣿��ʹ�� help ָ��鿴����ָ�\n");
        seteuid(ROOT_UID);
        act = lower_case(act);
        id = lower_case(id);
	if (id == me->query("id"))
		return notify_fail("�㲻�������ﴦ�����Լ���id�������µ�½��\n");
    	if (!stringp(file = (string)DIR+act)
   	 || file_size(file + ".c") <= 0 )
   		return notify_fail("��Ҫ���ʲô���⣿\n");

	// check player's rights
	if (check_valid_player(me->query("id"), id))
		return notify_fail("�Բ�����������֤ʧ�ܣ��޷�ʹ�ô�ָ�\n");
	
    	if (!(file_ob = find_object(file)) )
    		file_ob = load_object(file);
	ob = me;
	msg += file_ob->do_auto(me, id);
        // log_file
        log_file("static/office",
                sprintf("%s %sʹ��( %s )����ɹ�ִ�У�������Ϣ��%s",
			ctime(time()), geteuid(me), arg, msg));
	tell_room(this_object(),HIW"\n"+ob->name()+"����������ϣ�����һλ������\n"NOR);
	ob = 0;
	return notify_fail(msg);

}

int do_help(string arg)
{
	object me = this_player();
	object f;
	string output, *hp;
	int i;
	
	if (arg)
		return 0;
	output = "\n\n\t\t\t\t"HIG"�������˵��\n"NOR+
		"\n\n\t��������Ϸ������ʼ��������Զ�������ҵ��������������õ����������\n"+
		"\n\tĿǰ��ʱ���ŵ����������ָ��������£�\n\n";
	output += HIW"��������������������������������������������������������������������������������������\n";
	output += sprintf(HIW"��"HIY"%|20s"HIW"��"HIY"%|60s"HIW"��\n","����ָ��","ָ��˵��");
	output += HIW"�����������������������ة�������������������������������������������������������������\n";
        for (i=0;i<sizeof(file);i++) {
    	        if (!(f = find_object(DIR+file[i])))
    			f = load_object(DIR+file[i]);
    		hp = f->help();
    		output += sprintf(HIW"��"GRN"%-20s  "NOR"%-60s"HIW"��\n","ido "+hp[0],hp[1]);
        }
        output += HIW"��������������������������������������������������������������������������������������\n";
        output += HIR"ע�⣺"HIC"�������������Ҫ�������ô��ע����һ����ͬ����� id ����ע������˴�\n���������� \n\n"NOR;
        output += "\t�����κ�������кν��飬������ʦ�鱨�档\n\n\n"+
        	"\t\t\t\t\t\t"HIW"�齣"HIC"��ʦ��"HIY"���������칫��\n"NOR;
        me->start_more(output);
        return 1;
}
