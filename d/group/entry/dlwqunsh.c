// Room: /d/dali/qunshan.c
// bbb 1997/06/10 
// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "÷��ѩɽ");
	set("long", @LONG
����߷������������ѩ�����������ִ���ɽ������ٲȻ��һ����ѩ���硣
����֮�������ֻ�ѩ�ڻ�����ˮк���£��������գ�εΪ��ۡ������վ�����
�Ⱥܶ������������ֱ�߾���Ϊʮ�����������С����͵ĸ�ɽ�ݹȵ��Σ�
�Ǻ����ľ��ۡ�
LONG
	);
        set("outdoors", "�������");
	set("group", 1);
	set("exits", ([
		"southeast" : "/d/dali/daliwest/futiao",
		"southwest" : "/d/dali/daliwest/tianchi1",
	]));

	setup();
}
