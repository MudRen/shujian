inherit ITEM;
void create()
{
        set_name("��ҳ����", ({ "liangye daofa", "paper","book"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "���ƺ���һ�����ϲ�ȱ�ļ�ҳ���ڵ������顣\n");
                set("unique", 1);
                set("treasure",1);                              
                set("value", 1000);
                set("material", "paper");
        }
}
