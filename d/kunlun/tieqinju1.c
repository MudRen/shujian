// tieqinju.c ���پ�

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short",MAG"���پӶ�¥"NOR);
        set("long",@long
������ǡ�������������̫��ľӴ���¥�����������Ϊ���ɣ���Ʒ��������
�����ǲ�ͬ��������ɱ�ѩ�����Ǵ��ס�
long);

        set("objects",([
           CLASS_D("kunlun")+ "/hetaichong.c" :   1,
           CLASS_D("kunlun")+ "/xihuazi.c" :   1,
           __DIR__"npc/kl-dizi2.c" :   1,
           __DIR__"npc/kl-dizi4.c" :   1,
        ]));

        set("exits", ([
             "down" : __DIR__"tieqinju", ]));

        set("no_clean_up", 0);
        setup();
}
