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
"southdown" : __DIR__"hclu-4",
"northwest" : __DIR__"hclu-6",
]));

	set("no_clean_up", 0);
        set("outdoors", "tiezhang");
	set("coor/x",-350);
  set("coor/y",-150);
   set("coor/z",60);
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
