#include <ansi.h>
inherit ITEM;
void create()
{
        switch(random(10)) {
               case 0 : set_name(HIW "�����Ϻ�ͼ" NOR, ({ "tu", "art"})); break;
               case 1 : set_name(HIG "ɽ������ͼ" NOR, ({ "tu", "art"})); break;
               case 2 : set_name(HIR "������" NOR, ({ "tie", "art"})); break;
               case 3 : set_name(HIB "�˿�ͼ" NOR, ({ "tu", "art"})); break;
               case 4 : set_name(HIY "��ɽ����ͼ" NOR, ({ "tu", "art"})); break;
               case 5 : set_name(HIM "�Ὣ��ʫ��" NOR, ({ "tie", "art"})); break;
               case 6 : set_name(HIC "������ʸ�" NOR, ({ "ci", "art"})); break;
               case 7 : set_name(CYN "���±���ͼ" NOR, ({ "tu", "art"})); break;
               case 8 : set_name(BLU "���񳯷�ͼ" NOR, ({ "tu", "art"})); break;
               case 9 : set_name(MAG "�λ�������" NOR, ({ "tie", "art"})); break;
        }
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("value", 300000);
                set("unit", "��");
                set("weight", 100);
                set("material", "paper");
                }
        setup();
}

