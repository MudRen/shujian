// shanyao.c  ��ɽ��
// Modify By River@SJ 99.06
// Modify By Looklove@SJ 2000.10.24

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
    set("short", HIG"��ɽ��"NOR);
    set("long",@LONG
���Ѿ���������ɽ��İ��������ڴ˷庣�μ��ߣ����������ѱ�ض��Ǳ�
ѩ�ˣ��������ڱ�ѩ���棬�����������Ϊ������Ŀ��ɽ��ǰ�治Զ֮������
�£���ɭ������ס��˴����������ѩ��������һ��ȴ���󾭳��������ְ�
����������¶��һ��С��(dong)��ǡ������һ���򶫷�����һ��С·��ֱ��
��һƬ��ɭ��֮�䡣
LONG);
    	set("exits",([
        	"northdown" : __DIR__"sshanlu6",
        	"eastup"   :     __DIR__"ljroad1",
    	]));
    	set("item_desc", ([
		"dong" : "�ںڵ�һ��ɽ����ʲôҲ��������\n",
    	]));
    	set("coor/x",-320);
  	set("coor/y",110);
   	set("coor/z",80);
	setup();
    	set("outdoors", "���̹�����");
}
void init()
{
       	object me = this_player();
        if(me->query_temp("mj/xunluo") && !me->query_temp("shanyao"))
           me->set_temp("shanyao",1);
        add_action("do_enter","enter");
	add_action("do_enter","zuan");	
}

int do_enter(string arg)
{
	mapping fam;
       	object me;
       	object *obj;
       	
	me = this_player();
       	if (arg != "dong") return 0;
       	
	if((fam = me->query("family")) && fam["family_name"] != "����" )
       		return notify_fail("����������أ��㲻�����̵ģ�Ҳ���ȥ�𣿣�\n");

	obj = filter_array(deep_inventory(me),(: userp :));
	if(sizeof(obj)){
       		tell_object(me,"�㸺�ع��࣬һ��С�ģ�ͷײ��ɽʯ�ϡ�\n");
       		obj[0]->move(environment(me));
       		me->unconcious();
		return 0;
    	}
       	message("vision",me->name() + "һ�������������˽�ȥ��\n",environment(me), ({me}) );
       	me->move(__DIR__"didao/bidao19");
       	message("vision",me->name() + "�Ӷ������˽�����\n",environment(me), ({me}) );
       	return 1;
}
