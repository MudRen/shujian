// By River 98/12/
inherit ROOM;

void create()
{
	set("short", "˾����");
	set("long", @LONG
����һ������ûʵĹ��ã��Ǵ����˾�հ���ʯƽ���������˾����˾
�չ�Ͻ����������˰�񡢵�·�����޽��ȡ���˾��Ҫ������æ���İ��ϸ�
�߶���һ�����ġ�
LONG
	);        
	set("exits", ([
           "south" : __DIR__"yamen",            
	]));

        set("objects", ([              
              __DIR__"npc/sikong" : 1,
        ]));

	set("coor/x",-330);
  set("coor/y",-360);
   set("coor/z",-20);
   setup();
}
