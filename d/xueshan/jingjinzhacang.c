// Room: jingjinzhacang.c

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
һ�������İ�Բ�εĴ���ã��Ե���ɫש���ɡ�����������������ɫ
�ڻ������ݾ�Ϊ����������������ġ�����ǽ�߰�Щ�������õ����ߣ�����
��������������������ϰ��
LONG
	);

	set("exits", ([
		"north" : __DIR__"jingtang",
		"west" : __DIR__"hufazhacang",
	]));
        set("objects", ([CLASS_D("xueshan") + "/shanyong" : 1,]));
	setup();
}
