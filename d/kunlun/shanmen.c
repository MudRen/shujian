// shanmen.c (kunlun)

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	 set("short", "������ɽ��");
	 set("long",@long
��һ·���������ܴ���ɳ֮�࣬������ľ������������ʱ������֦Ҷ��
������������·�߲ݴ�ż��Ҳ�ܷ���һЩ���ŵ�Ұ���������������������
����ʮ��ïʢ��������û�뵽��ɽ��ȴ��������ڣ������Ϊһ��ǰ����һ
��ɽ�ţ�д�š������ɡ��������֡�
long);
	 set("exits",([
            "eastup" : __DIR__"shanlu01",
            "southdown" : __DIR__"klshanlu",
         ]));

         set("objects",([
            CLASS_D("kunlun") + "/jiangtao" : 1,
            __DIR__"npc/kl-dizi1" :  1,
	    __DIR__"npc/kl-dizi2" :  1,
         ]));

         set("outdoors", "����");
         setup();
}
