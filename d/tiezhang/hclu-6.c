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
"northup" : __DIR__"wmfeng",
"southeast" : __DIR__"hclu-5",
]));

	set("no_clean_up", 0);
        set("outdoors", "tiezhang");
	set("coor/x",-360);
  set("coor/y",-140);
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