//hclu-2.c �Ĳ�·

inherit ROOM;


void create()
{
	set("short", "�Ĳ�·");
	set("long", @LONG
����һ�����ߵ�С·�ϣ����ԻĲ���ϥ��������أ��ƺ�����������ɽʯ������
������գ�����ȫ�ޣ�����������һƬ����֮�У�ʹ���￴�������������ľ���
LONG
	);

	set("exits", ([
"southdown" : __DIR__"hclu",
"northwest" : __DIR__"hclu-3",
]));

	set("no_clean_up", 0);
        set("outdoors", "tiezhang");
	set("coor/x",-340);
  set("coor/y",-180);
   set("coor/z",40);
   setup();
}
int valid_leave(object me, string dir)
{
        if ((dir != "northwest") && (dir != "southdown"));
        if (dir == "northwest"){
            me->receive_damage("qi", 100);       
            write("���˫�ȱ��������ƣ���Ѫ���˳�����\n");
        }

        if (dir == "southdown"){
            me->receive_damage("qi", 100);       
            write("���˫�ȱ��������ƣ���Ѫ���˳�����\n");
        }
        return 1;
}
