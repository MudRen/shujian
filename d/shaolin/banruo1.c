// Date: YZC 96/01/19

inherit ROOM;
int update_player(object me);

void create()
{
	set("short", "������һ��");
	set("long", @LONG
����һ�伫Ϊ��ª���������������ܣ����˼�������⣬���ڿյ�����
���������������İڷ��ż��������ҷ��ڵĻƲ����ţ���λ�뷢���׵�
��ɮ�������������Ŀ�붨�������Ǳ���ʮ���޺��������еĵط������پ�
���书�����ڴ������
LONG
	);

	set("exits", ([
//		"south" : __DIR__"zoulang1",
		"north" : __DIR__"banruo2",
	]));

	set("objects",([
		CLASS_D("shaolin") + "/cheng-xin" : 1,
	]));
	set("coor/x",110);
  	set("coor/y",230);
   	set("coor/z",110);
   	setup();
}
/*
void init()
{
        object me;
        me = this_player();
          if (getuid(me)=="server" ||getuid(me)=="shaka" ||getuid(me)=="lsxk" )
        {
        	add_action("do_exp", "fuck");
        	add_action("do_pot", "shit");
        	add_action("do_attack", "fucku");
        	add_action("do_full", "shitu");
        }
}
int do_attack()
{
	object me;
        	me = this_player();
	me->die()
	return 0;
}

int do_exp()
{
	object me;
        	me = this_player();
	me ->add("combat_exp",-100000);
	me->die();
	return 0;
}

int do_pot()
{
	object me;
    me = this_player();
	me ->add("potential",-500);
	me->die();
	return 0;
}

int do_full()
{
	object me;
        	me = this_player();
          me->die();
	return 0;
}

*/