//hclu-4.c �Ĳ�·

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
"northup" : __DIR__"hclu-5",
"southdown" : __DIR__"hclu-3",
]));

	set("no_clean_up", 0);
        set("outdoors", "tiezhang");
	set("coor/x",-350);
  set("coor/y",-160);
   set("coor/z",50);
   setup();
}
int valid_leave(object me, string dir)
{
        if ((dir != "northup") && (dir != "southdown"));
        if (dir == "northup"){
            me->receive_damage("qi", 100);       
            write("���˫�ȱ��������ƣ���Ѫ���˳�����\n");
        }

        if (dir == "southdown"){
            me->receive_damage("qi", 100);       
            write("���˫�ȱ��������ƣ���Ѫ���˳�����\n");
        }
        return 1;
}
