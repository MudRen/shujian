// By River 98/12/
inherit ROOM;

void create()
{
	set("short", "˾ͽ��");
	set("long", @LONG
һ���徲�����ã���ɨ�øɸɾ�����������˾ͽ�����޵�˾����˾ͽһ��
�������ѡ�ε����鹤�������������ľ�ѻ���ʱ�й�Ա���˰���ӡ�����ĵ�
�ǰ������ǲ���εع��ɡ�
LONG
	);        
	set("exits", ([
           "west" : __DIR__"yamen",            
	]));

        set("objects", ([              
                __DIR__"npc/situ" : 1,
        ]));

	set("coor/x",-320);
  set("coor/y",-370);
   set("coor/z",-20);
   setup();
}
