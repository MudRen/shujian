// Write By Yanyang@SJ 2001.9.20
// Room: /d/changan/juhao2.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "��¥��¥");
	set("long", @LONG
�����Ǿۺ���¥�Ķ�¥�������ڿ�������ǽ�Ϲ���������ѧʿ���ֻ���
�ۺ���¥������ƽʱ�����������һ�����ո�Ҫ��ǰ�����¾�ϯ��վ��¥
��������ֻ�����Ŀ�������
LONG
        );
	set("no_get",1);
	set("no_drop",1);
	set("no_fight",1);
	set("exits", ([
		"down" : __DIR__"juhao",
	]));

	set("incity",1);
	setup();
}

void init()
{       
	object ob=this_object();
	object me=this_player();
	object obj;

	if (me->query_temp("see_zhubanren",1)<1 && ob->query("doing",1)>0) {
		obj=new(FOOD_D("caiyao"));
		obj->move(me);
		obj=new(FOOD_D("caiyao"));
		obj->move(me);
		obj=new(FOOD_D("caiyao"));
		obj->move(me);
		obj=new(FOOD_D("caiyao"));
		obj->move(me);
		obj=new(FOOD_D("caiyao"));
		obj->move(me);
		obj=new(FOOD_D("caiyao"));
		obj->move(me);
		obj=new(FOOD_D("caiyao"));
		obj->move(me);
		obj=new(FOOD_D("caiyao"));
		obj->move(me);
		obj=new(FOOD_D("caiyao"));
		obj->move(me);
		obj=new(FOOD_D("caiyao"));
		obj->move(me);
		obj=new(FOOD_D("jiutan"));
		obj->move(me);
		obj=new(FOOD_D("jinbei"));
		obj->move(me);
		write("������¥����С����æ��������һ��λ���¡�����������Ŀ�����Ƽ���ʹ�㴹�����Σ�\n");
		me->set_temp("see_zhubanren",1);
	}
	add_action("do_start", "start");
	add_action("do_theend", "theend");
	add_action("do_quit","quit");
	add_action("do_kickout","kickout");
}

int do_start()
{
	object me=this_player();
	object ob=this_object();
        
	if(me->query_temp("zhubanren") != 1) return notify_fail("���ֲ��������ˣ�Ϲ����ʲô��\n");
	if(ob->query("doing")>0) return notify_fail("��ϯ�����Ѿ���ʼ����\n");
	ob->set("doing",1);
	message("shout", HIC"\n�����ġ���¥�ƹ�(Zhanggui)��" + me->short(1) +HIC" \n\t\t�����ڳ����ۺ���¥���С�"HIR""+me->query_temp("��ϯ")+""HIC"�������·Ӣ�ۺ��ܡ�\n\n" NOR, users());
        message_vision(""BLINK+HIR"$N��"+ me->query_temp("��ϯ",1) +"��ʼ�ˣ�"NOR"\n",me); 
        write("������á�"HIW"theend"NOR"�������������ϯ��\n�������á�"HIW"kickout"NOR"�������㲻ϲ���Ŀ��ˣ����ǽ������ٲμ����ľ��磡\n");
        call_out("time_theend", 3600);
        return 1;
}

int do_theend(string arg)
{
	object me=this_player();
	object ob=this_object();
	object obj;
        mixed *ob_list;
        int max,i;
        
        if (me->query_temp("zhubanren",1)<1) return notify_fail("���ֲ��������ˣ�Ϲ����ʲô��\n");
        if (ob->query("doing",1)<1) return notify_fail("����û�о��о��磡\n");
       	message("shout", HIC"\n�����ġ���¥�ƹ�(Zhanggui)��" +me->short(1) +HIC" �ġ�"HIR""+me->query_temp("��ϯ")+""HIC"�������ˡ�\n\n" NOR, users());
        message_vision(""BLINK+HIR"$N��"+ me->query_temp("��ϯ",1) +"�����ˣ�"NOR"\n",me); 
        me->delete_temp("zhubanren",1);
        me->delete_temp("��ϯ",1);
        ob->delete("doing",1);

	ob_list = filter_array(children(USER_OB), (: clonep($1) && !wizardp($1) :));
	max=sizeof(ob_list);
	for(i=0;i<max;i++) {
		obj = ob_list[i];
		obj->delete_temp("see_zhubanren");
		obj->delete_temp("getout");
	}
	return 1;
}

int do_quit()
{
	object me=this_player();
	if (me->query_temp("zhubanren")) {
		write("�����ϯ��û�н�����������ô���뿪��\n");
		return 1;
	}
	else return 0;
}

int do_kickout(string arg)
{
	object me=this_player();
	object him;

        if (me->query_temp("zhubanren",1)<1) return notify_fail("����Ϊ����˭��\n");
	if (!arg) return notify_fail("��Ҫ��˭�뿪�����ϯ��\n");

	him=find_player(arg);
	if(!him) return notify_fail("�����û�������ϯ�У�\n"); 
	if(him!=present(him,environment(me))) return notify_fail ("�����û�������ϯ�У�\n"); 

        message_vision("$N������¥�ƹ񣬽�"+ (string)him->query("name") +"("+ (string)him->query("id") +")�ϳ�����ϯ��\n", me); 
        him->set_temp("getout",1);
        him->move(__DIR__"juhao");
        tell_object(him,"�㱻�ƹ������¥�£������������ǲ���ӭ���ٽ�ȥ�ˣ�\n");
        
        return 1;
}

int time_theend(string arg)
{
	object ob=this_object();
	object obj;
        mixed *ob_list;
        int max,i;
        
        if (ob->query("doing")<1) return 1;
       	message("shout", HIW"\n��¥�ƹ񣺳����ۺ���¥���е���ϯ�����ˡ�\n\n" NOR, users());
        ob->delete("doing",1);
        
        ob_list = filter_array(children(USER_OB), (: clonep($1) && !wizardp($1) :));
        max=sizeof(ob_list);
        for(i=0;i<max;i++) {
		obj = ob_list[i];
		obj->delete_temp("zhubanren");
		obj->delete_temp("��ϯ");
		obj->delete_temp("see_zhubanren");
		obj->delete_temp("getout");
	}
	return 1;
}

int valid_leave(object me,string dir)
{
	object ob=this_object();
	if( dir=="down" && me->query_temp("zhubanren",1)>0 && ob->query("doing",1)>0 )
		return notify_fail("�����ϯ��û�н�����������ô���뿪��\n");
	return ::valid_leave(me,dir);
}
