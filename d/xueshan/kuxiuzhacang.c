// Room: kuxiuzhacang.c

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
һ�������������εĴ���ã�����ש���ɡ�����������������ɫ�ڻ���
���ݾ�Ϊ����������������ġ�����ǽ�߰�Щ�������õ����ߣ�����������
��������������ϰ��
LONG
	);

	set("exits", ([
		"north" : __DIR__"jingangyuan",
		"east" : __DIR__"hufazhacang",
	]));
        set("objects", ([ CLASS_D("xueshan") + "/shengdi" : 1 ]));
	setup();
}
