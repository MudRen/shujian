//hguangz1.c

inherit ROOM;

void create()
{
	set("short", "���㳡");
	set("long", @LONG
�����Ǻ��㳡���ɴ���ʯ��ƴ�ɵĵ������м�����͹��̤�ۣ�������
ǰ�и���ʩչ�ڹ���������ӡ�ǡ���λִ��ɮ������Ľ�����ɨ��
LONG
	);
        set("outdoors","shaolin");
	set("exits", ([
		      "east" : __DIR__ "hguangz2",
                      "north" : __DIR__ "hguangz4",
                      "southwest" : __DIR__ "huaishu5",
                      ]));
	set("coor/x",40);
  set("coor/y",330);
   set("coor/z",120);
   set("coor/x",40);
 set("coor/y",330);
   set("coor/z",120);
   setup();
	
}
int init()
{
//     add_action("do_ta","ta");   
}

int do_ta(string arg)
{         object me;
	me = this_player();
 if ( !living(this_player()) || arg != "sign" )
                 return 0;
        if ((int)me->query_skill("leg", 1) > 31)
        return notify_fail("��̤��ӡ�Ѿ��޷��������Ļ����ȷ��ˣ�\n");
        if ( (int)me->query("jing")<30) {
                 me->receive_damage("jing", 10);
                 write("��̫���ˣ��Ѿ�û����������̤��ӡ�ˣ�\n");              
        return 1;
}
        me->receive_damage("jing", random(35));
        message_vision("$N���ڲ�̤�����ϵĽ�ӡ��\n", me);  
        write("����ò�̤��ӡ����Ļ����ȷ������ٽ���\n");
                  me->improve_skill("leg", me->query("int"));       
         return 1;
}


