//shufang.c �鷿

inherit ROOM;
void create()
{
          set("short","�鷿");
          set("long",@LONG
����һ���鷿�����ڳ������ڶ������徭������һЩ�����书�鼮���Թ�
���ư�����Ķ���
LONG
    );

           set("indoors","���ư�");
           set("exits",([
"south": __DIR__"zoulang-2",
]));

            set("objects",([
__DIR__"obj/brush_book": 1,
]));
            set("no_clean_up", 0);
            set("coor/x",-340);
  set("coor/y",-240);
   set("coor/z",10);
   setup();
}