// Room: /d/city/nandajie3.c

inherit ROOM;

void create()
{
	set("short", "�ϴ��");
	set("long", @LONG
�ϴ���������ݳ���ķ����ضΣ�һ�����ϣ�һ�ɵƺ���̣���Ϊ���֡�
Ц�������������������������һƬ��������Ķ��䣬�㲻����Գ��������
�ʹ�ͣ������һ������������һ�����ֵĹ㳡��������һƬ�����������š�һ
��һʮ������Ǯ����ԭ�������Ƿ�Բǧ��֮������һ�Ҷĳ���
LONG
	);
        set("outdoors", "����");
	set("exits", ([
		"east" : __DIR__"guangchangnan",
		"south" : __DIR__"nandajie2",
		"west" : __DIR__"duchang",
	        "north" : __DIR__"guangchangxi",
	]));

        set("objects", ([
                CLASS_D("gaibang/xqigai") : 1,
                CLASS_D("gaibang/lqigai") : 1,
        ]));
	set("incity",1);
	setup();
}
