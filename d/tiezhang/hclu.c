//hclu.c �Ĳ�·

inherit ROOM;


void create()
{
	set("short", "�Ĳ�·");
	set("long", @LONG
����һ�����ߵ�С·�ϣ����ԻĲ���ϥ��������أ��ƺ�����������ɽʯ
������������գ�����ȫ�ޣ�����������һƬ����֮�У�ʹ���￴������
�������ľ���
LONG
	);

	set("exits", ([
"southeast" : __DIR__"pingtai",
"northup" : __DIR__"hclu-2",
]));

	set("no_clean_up", 0);
        set("outdoors", "tiezhang");
	set("coor/x",-340);
  set("coor/y",-190);
   set("coor/z",30);
   setup();
}
int valid_leave(object me, string dir)
{
            if ((dir != "northup") && (dir != "southeast"));
            if (dir == "northup"){
            me->receive_damage("qi", 50);       
            write("���˫�ȱ��������ƣ���Ѫ���˳�����\n");
            }

            if (dir == "southeast"){
            me->receive_damage("qi", 50);       
            write("���˫�ȱ��������ƣ���Ѫ���˳�����\n");
            }
            return 1;
}
