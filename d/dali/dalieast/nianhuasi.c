// Modify By River 98/12
inherit ROOM;

void create()
{
        set("short", "�¼�С·");
	set("long", @LONG
��ٲ����£�ֻ���ö����������࣬���ƴӺ�Ժ��������ʱ֮�䣬ֻ�б�
���������⾲���С�
LONG
	);
	set("outdoors", "����");
	set("exits", ([ /* sizeof() == 1 */
		"out" : __DIR__"simen",
		"north" : __DIR__"yuan1",
	]));
       
	setup();
}
