// Room: /d/huashan/jinshe/obj/xinjian1.c
// Date: Look 99/03/25

#include <ansi.h>

inherit ITEM;
void setup()
{}
void create()
{
        set_name( "һ�����", ({ "xin jian"}));
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",RED
"\n������һ������ɾ��������ӵļ��ţ�
\n������Ե�˽����Ž���������:����.
\n��ס���������¼ұ�������������ó�
\n��֮�����֪��,Ҫ��Ҫ����
\n���ҽ���׶��������,����֤����֮���
\n�ƶ��в�(move ancheng)���Կ��������ϲ㣬�õ�����׶����\n"
"\n"NOR);

                set("value", 1000);
                set("material", "paper");
                set("no_get", "�������������뿪�Ƕ���\n");
        }
}

