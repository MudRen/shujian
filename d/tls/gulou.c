inherit ROOM;

void create()
{
	set("short", "��¥");
	set("long", @LONG
����һ��שľ�ṹ��С¥���������ᣬ�ܽ��Ϲ�����һ����Сͭ
�壬��綣�����졣ǽ���οյ�������������ǵ�����һ������̬
άФ��¥�ڸ�����һ����ģ������ϻ��з�������Ĳ������������˵
���Ĳʻ档
LONG);
	set("exits", ([
		"west" : __DIR__"road1",
                "south"  : __DIR__"zt",
                "north"  : __DIR__"yaoshidian",
	]));
	set("coor/x",-340);
  set("coor/y",-340);
   set("coor/z",30);
   setup();
}





