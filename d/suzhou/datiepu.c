inherit ROOM;
void create()
{
	set("short", "������");
	set("long", @LONG
����һ�Ҽ�ª�Ĵ����̣����İ���һ����¯��¯��������յ�һƬͨ�죬
��һ�߽�ȥ�͸е�������ȡ�ǽ�Ƕ��������깤��δ�깤�Ĳ˵�����������
����ذ�ס����׵��һλ������ͷ�󺹻�����������ר����־���ڴ�����
LONG
	);
        set("objects",([
                __DIR__"npc/tiejiang" : 1,
        ]));
	set("exits", ([
		"north" : __DIR__"dongdajie2",
	]));

	set("coor/x",150);
  set("coor/y",-220);
   set("coor/z",0);
   set("incity",1);
	setup();
}

