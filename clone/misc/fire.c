// item: fire.c
// by snowman@SJ , 01/05/1999.

inherit FIRE_ITEM;
void create()
{
        set_name("����", ({"fire", "huozhe"}));
        set_weight(80);
        if (clonep())
                set_default_object(__FILE__);
        else {
         set("long", "����һ֧��������Ļ��ۣ����˺ڰ��ĵط�����(use)�����ˡ�\n");
                set("unit", "֧");
                set("value", 100);
                set("light/time", 15);
        }
        setup();
}


