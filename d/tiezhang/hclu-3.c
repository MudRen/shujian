//hclu-3.c �Ĳ�·

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
"southeast" : __DIR__"hclu-2",
"northup" : __DIR__"hclu-4",
]));

	set("no_clean_up", 0);
        set("outdoors", "tiezhang");
	set("coor/x",-350);
  set("coor/y",-170);
   set("coor/z",40);
   setup();
}
int valid_leave(object me, string dir)
{
        if ((dir != "northup") && (dir != "southeast"));
        if (dir == "northup"){
            me->receive_damage("qi", 100);       
            write("���˫�ȱ��������ƣ���Ѫ���˳�����\n");
        }

        if (dir == "southeast"){
            me->receive_damage("qi", 100);       
            write("���˫�ȱ��������ƣ���Ѫ���˳�����\n");
        }
        return 1;
}
