// /d/hz/gushan.c ��ɽ

inherit ROOM;
void create()
{
	set("short","��ɽ");
	set("long", @LONG
��������������ں�֮�䣬���ǹ�ɽ����ʵ��һ��С�������������㣬
�ֶ�÷����ÿ������֮�գ����ն���֮ʱ�����ۺ��ϣ����׹�ɽ����ѩ������
����������¥����֮�С��ƴ�ʫ�˰׾�����ʫ�ƣ������������ͷ��������
����ˮ���롱����ɽ�Ķ����׵̣�������������š�
LONG
        );
	set("outdoors", "����");
	set("exits", ([
		"east" : "/d/meizhuang/hubian",
		"west" : __DIR__"xilengqiao",
		"northeast" : __DIR__"baidi",
		"south" : __DIR__"wenlange",
		"north" : __DIR__"fangheting",
	]));
   	setup();
}
