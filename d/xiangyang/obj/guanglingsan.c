// /d/xiangyang/obj/guanglingsan.c
// By Jpei

inherit ITEM;

void create()
{
        set_name("����ɢ", ({ "guang ling san", "san", "qinpu", "pu" }) );
	set("long", "����������Ĺ���ɢ�����ˡ�����Ϊ���������ʧ���ˣ�û�뵽ȴ���ڲ��ߵ�Ĺ�з��֡�\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("no_get", "�����޼�֮�����Է���˯�������ڻ���ģ�\n");
                set("no_drop", "������޼�֮��������ô�ϴ�һ���ˣ���Ȼ��˲�ʶ������\n");
		set("value", 1000000);
	        set_weight(85);
//		set("treasure", 1);
        }
        setup();
}

