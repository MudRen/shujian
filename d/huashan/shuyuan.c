// Room: /d/huashan/celang4.c
// Date: Look 99/03/25

inherit ROOM;

void create()
{
        set("short", "��Ժ");
        set("long", @LONG
�����ǻ�ɽ�ɵ���Ժ��ƽʱ��ɽ�ɵ�����ϰ��֮�࣬�����ʦ������ѧϰ
�书�ؼ���������Լ�����Ϊ���ر��ǻ�ɽ�ķ���
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"celang4",
		"north" : __DIR__"wuqiku",
	]));

	set("objects",([
		__DIR__"obj/zhengqijue" : 1,
//        __DIR__"obj/ziyin_book" : 1,
	]));

	set("no_clean_up", 0);
	set("indoors", "��ɽ" );

	set("coor/x",100);
  set("coor/y",-30);
   set("coor/z",80);
   setup();
}
