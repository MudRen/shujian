// Room: /dali/dongjie3.c
// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�����ڴ���Ķ�����ϣ��ֵ��ϻ��ݺ���ľ�����дУ��������󡣶�����
�������־��ı�Ӫ�������߹�����Ȼ�������������߾͵���̫�Ͷ��֡�
LONG
	);
	set("outdoors", "����");
	set("exits", ([
		"east" : __DIR__"bingying",
		"south" : __DIR__"dongjie4",
		"north" : __DIR__"dongjie2",
	]));
	setup();
}
