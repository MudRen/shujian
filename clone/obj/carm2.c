//Cracked by Kafei
// Carriage2: /clone/obj/car2.c ������
// Date: xbc /04/14/97

inherit ITEM;

void create()
{
        set_name("������", ({ "da che", "che", "carriage" }) );
        set_weight(3000000);
        set_max_encumbrance(5000000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", @LONG

���� - 
����������踻�����������ź��ĵ�̺��һֻС���ϰ������ϸ�㡣һ��
����Ĵ󴲣��������һ�������ı��ӡ�������������������ӷ�϶��͸
��������֪�������ߵ������ˣ�����ֻ����������˲�ͣ���ߣ��ߵ�����
���ǣ��ع�ͷ�����ֵ��˶˵����ĺ��ǣ����µĵ�·��Զ���߲��꣬������
���ˣ���·���߼������кη���
������������������ޣ��������У�ֻ�³����Ȼ˵�Ѿ����ˡ���������
�У����Ժ����Ĳ�֪ʱ��֮������·֮ң��

LONG
	);

                set("amount",30);
        }
        setup();
}

int is_container() { return 1; }

