// Room: /d/fuoshan/grocer.c 
 
inherit MISC_ROOM; 
 
void create() 
{ 
	set("short", "�ӻ���");
	set("long", @LONG
����һ��ոտ��ŵ��ӻ��̣������С�����Ķ���һЩ�ճ���Ʒ����
˵�ϰ��Ǵ�������ģ�����ȥ���ؽ�һЩ���õ���Ʒ��
    ��ǰ���˸�����(sign)��
LONG
	);
        set("item_desc", ([
                "zhaopai": "�����\n",]));

	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"dongjie",
]));
        set("objects", ([
                __DIR__"npc/li": 1,]));

	set("no_clean_up", 0);

	set("coor/x",10);
  set("coor/y",-520);
   set("coor/z",0);
   setup();
}
