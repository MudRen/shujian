
inherit ITEM;

void create()
{
        set_name("����",({ "lanyu bo", "bo" }) );
        set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                set("long", "һֻ���������ƶ��ɵ�ҩ������Ȼʹ���վ�, ��˿��û���ƺۡ�ҩ���������΢���綾, Ȼ���㹻����͵��֮�ˡ�\n");
                set("value", 500000);
        }
        setup();
}
