// bqshi.c ������

inherit ROOM;

void create()
{
       set("short", "������");
       set("long", @LONG
���ư��������Ʒ����Ṧ���ƣ��������Դ��д����ı������Թ��书����
�İ���ʹ�á������������еĶ��Ǳ����ܣ����浶��ǹ������ꪡ������ᡢ����
��Ӧ�о��С�
LONG   );
       set("exits", ([ 
  "south" : __DIR__"zoulang-1",
]));
    set("objects", ([ 
__DIR__"obj/jia": 1,
]));
       set("no_clean_up", 0);

       set("coor/x",-320);
  set("coor/y",-240);
   set("coor/z",10);
   setup();
}
