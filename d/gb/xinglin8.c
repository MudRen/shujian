// /d/gb/xinglin8
// by pishou
// Lklv modify 2001.9.27

inherit ROOM;

void create()
{
    set("short", "������");
       set("long", @LONG
������������м��һƬ�յأ����ܵ������Ͽ����˻���һȺ�۷������
ȥ��æ�ز��ۡ������м�����ؤΧ����һ���Ա�վ������������ؤ��������
ɫ���أ�������������ʲô��
LONG
       );
	set("outdoors", "����");
	set("exits", ([
		"south" : __DIR__"xinglin7",
		"north" : __DIR__"xinglin9",
	]));

        set("objects", ([
		CLASS_D("gaibang/song") : 1,
		CLASS_D("gaibang/zfdizi") : 1,
                CLASS_D("gaibang/bai") : 1,
        ]));

	setup();
}