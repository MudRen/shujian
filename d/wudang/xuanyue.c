// /d/wudang/xuanyuemen.c ������
// By River@SJ

#include <ansi.h>
#include <wanted.h>

inherit ROOM;

void create()
{
        set("short", HIY"������"NOR);
        set("long", "�����ǰ���������������䵱ɽ������һ����ľ��ï�ĸ�ɽ������ɽ�屻
�������֣��Ѽ�ȫò��һ��ʯ���������ϣ���Լ�ɼ���������͡�һ������ʯ
��(fang)��ɽ�������䵱ɽ����̫��ɽ��Ϊ��ʮ������֮һ���ж�ʮ�߷塢��
ʮ���ҡ���ʮ�Ľ�����̨���微����̶�������š��������һ���أ���������
��ɭ�ޣ����ղ��죬�����ľ����������������䵱��ӭ�����͵ĵ�һվ��
"HIG"\n\t\t\t  ��  ��  ɽ\n\n"NOR
        );

        set("exits", ([
                "east" : __DIR__"wdroad8",
                "southup" :__DIR__"shijie1",
        ]));
        set("outdoors","�䵱");
        set("item_desc", ([
                "fang" : HIG"\n
                    ������������������
                ��    ����������������   
                      ����        ����  
                      ����   ��   ������ 
                      ����        ������ 
                      ����        ������                         
                      ����   ��   ����  
                      ����        ������                          
                      ����        ������������������������������ 
                      ����   ɽ   ����
                      ����        ���� 
                      ����������������
                      ����������������\n\n"NOR,
        ]));
        
        setup();
}

int valid_leave(object me, string dir)
{
       if (dir == "southup" && is_wanted(me)) return 0;
        return ::valid_leave(me, dir);
}
