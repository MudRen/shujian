// Room: /d/tianshan/qiandian.c
// By Linux

inherit ROOM;

void create()
{
	set("short", "ǰ��");
	set("long", @LONG
���������չ���ǰ����ò��󣬵����ƷǷ���һ�����չ��Ŀ��˶��ڴ�
��ͯ�ѵİ��š��м���������������ɽ����ľ���Ƴɵ�̫ʦ�Σ�����һ�Ŵ���
ʯ��İ����������������ǰ������ӡ�
LONG);
	 set("exits", ([
                "west" : __DIR__"chufang",
		"north" : __DIR__"zoulang1",
		"south" : __DIR__"ljgong",
        ]));         
	setup();
}
