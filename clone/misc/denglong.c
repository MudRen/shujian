// item: denglong.c
// by snowman@SJ , 01/05/1999.

inherit FIRE_ITEM;
void create()
{
        set_name("����", ({"deng long", "deng", "light"}));
        set_weight(800);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һյֽ��ĵ��������˺ڰ��ĵط�����(light)�����ˡ�\n");
                set("unit", "յ");
                set("value", 100);
                set("light/time", 180);
        }
        setup();
}


