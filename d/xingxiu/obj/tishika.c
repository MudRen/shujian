// by tangfeng 8/2004

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIR"��ʾ��"NOR, ({ "tishi ka", "ka", "paper"}));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����������ʦ�Ķ������ƺ�����Ȫ���йء�\n\n"
                            +"��ʾһ���������ڹ�Ϊ����£�ѧϰ��Ȫ���ٶȼ��롣\n"
                            +"��ʾ����ѧ����Ȫ�񹦺󣬺��ҵ�������ҽ������ܷ���������������\n"
							+"��ʾ����Ѱ��ֽ�ţ�VIP���λ��ᣬ��ͨ���һ�λ��ᡣ\n"); 
                set("unique", 1);
                set("treasure", 1);
                set("material", "silk");
                set("no_give", "�������������뿪�㡣\n");
                set("no_get", "�������������뿪�Ƕ���\n");
        }
}
