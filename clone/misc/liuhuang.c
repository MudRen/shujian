// caiji@SJ

inherit ITEM;

void create()
{
        set_name("���", ({"liu huang", "liuhuang"}));
        set_weight(80);
        if (clonep())
                set_default_object(__FILE__);
        else {
         set("long", "����ɫ�Ľᾧ�壬���������������ᣬ��ҩ�����ȣ�Ҳ������������Ƥ������\n");
                set("unit", "��");
                set("value", 99);
        }
}
