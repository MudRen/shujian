// yugan2.c �ϵ������

inherit ITEM;

void create()
{
        set_name("�ϵ������", ({ "duan yugan",}) );
        set_weight(150);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ���ϵ�����ͣ������Ѿ�ûʲô���ˡ�\n");
        }
        setup();
}

