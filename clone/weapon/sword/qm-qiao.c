//by caiji@SJ 8/24/2000

inherit ITEM;

void create()
{
        set_name("����", ({"jian qiao", "qiao"}));
        set_weight(80);
        if (clonep())
                set_default_object(__FILE__);
        else {
         set("long", "��ڤ���Ľ��ʣ����԰���ڤ����(��)�����С�\n");
                set("unit", "��");
                set("value", 1);
        }
}
