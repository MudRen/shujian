// ������
// bqp.c -- Oct 25,97
// Looklove 2001/2/27

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
           set("short",HIR"������"NOR);
           set("long",@long
����һ��ƻ�ͨ���ı����̣���߷���һ���ŵı����ܣ���������˱�
����һλ��ʦ����һ�������������ڴ�����һ��ϣ��Źֵı����������û
�м��������������������ȥ�����Ǵ������ǽ����һ��������(sign)��
long ); 
        set("objects",([
        "/clone/npc/tiejiang_test" : 1,
        "/d/city/npc/tiejiang" : 1,
//	"/clone/npc/agent" : 1,
                ]));
                  
        set("exits",([
                "west" : __DIR__"datiepu",
                ]));
        
        set("item_desc",([
                "sign" : 
                "
                 ����ж����ֱ�����

                 ��     ding <weapon_type> <color> <weapon_name>  ������.
                        ���� : ding sword $HIY$ ��Ѫ��
                                 
                Notes: weapon_type   blade,sword,club,staff,feibiao,hook;
                        color         $HIG$ $HIR$ etc, see help nick
                             for the full list of supported color;
                        weapon_name   ����Ҫ����ı�������������

                        ***   ���ڲ��Ź۵ı���,��ʦ������û��!   ***\n"
           ]));
        set("coor/x",130);
        set("coor/y",-20);
        set("coor/z",0);
        setup();
}

