#include <room.h>

inherit ROOM;

void create()
{
        set("short", "���޹�");
        set("long",@LONG
��ס�����ࡢ��Ը���Ƿ�ҳ�˵�ġ����ޡ����ⱦ������������
�����������񣬿���¶����Ц������������֪��ɮ��������æµ��
����͡�����ͨ�����ʴ�ʿԺ��������һ��ʯ��·������ͨ������̨��
LONG);
        set("exits", ([
                "east" : __DIR__"men4",
		"northup" : __DIR__"shiyuan",  
                "westup" : __DIR__"longxiang1",            
	]));
	
        create_door("east", "ľ��", "west", DOOR_CLOSED);

        set("coor/x",-390);
  set("coor/y",-320);
   set("coor/z",20);
   setup();
}
