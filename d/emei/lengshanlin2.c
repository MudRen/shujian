// Room: /d/emei/lengshanlin1.c ������ ��ɼ��1

inherit ROOM;

void create()
{
	set("short", "��ɼ��");
	set("long", @LONG
����һƬ������յ���ɼ�֡�����Ҳ�ϱ�����������ɼ������һ�飬�ÿ�
֦��Ҷï����һ�����ɡ��������գ��������ڵ�˿��Ҳ�ޡ������Ϻ��Ŀ�
֦��Ҷ����Ȼ�οͺ���̤��˴���
LONG
	);

	set("exits", ([
		"northwest" : __DIR__"lengshanlin1",
		"northeast" : __DIR__"lengshanlin",
                "southwest" : __DIR__"lengshanlin2",
                "southeast" : __DIR__"basipan3",
	]));

	set("outdoors", "shaolin");
	setup();
}



