// letters.c
inherit ITEM;

void create()
{
        set_name("������", ({"letters"}));
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
"��������Ҹ������۵Ľ����ţ��������۴�����ִ�ŵ���Ϊͽ��\n");
                set("material", "paper");
        }
}

