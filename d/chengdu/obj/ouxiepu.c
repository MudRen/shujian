// /d/xiangyang/obj/ouxiepu.c
// By Jpei

inherit ITEM;

void create()
{
        set_name("ŻѪ��", ({ "ou xie pu", "go chart", "chart", "qipu", "pu" }) );
	set("long", "����ǰ�˱ʼ������ᵽ�������ٸ�����ɽ���ѵĶԾ֣���˵���ٸ�Ϊ�˶�ŻѪ����������Ϊֻ�Ǵ�˵��û�뵽��������������������\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("no_get", "�����޼�֮�����Է���˯�������ڻ���ģ�\n");
                set("no_drop", "������޼�֮��������ô�ϴ�һ���ˣ���Ȼ��˲�ʶ������\n");
		set("value", 1000000);
	        set_weight(12);
//		set("treasure", 1);
        }
        setup();
}

