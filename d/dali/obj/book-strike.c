// Modify By River 98/12
inherit ITEM;
void create()
{
       set_name("�Ʒ���Ҫ", ({ "zhangfa jueyao", "book", "jueyao" }));
       set_weight(250);
       if( clonep() )
	   set_default_object(__FILE__);
       else {
	   set("unit", "��");
	   set("long", "����һ�����ƾɵ�С���ӣ�ֻʣ��ǰ��ҳ������һЩ���Ʒ������ơ�\n");
	   set("value", 500);
	   set("material", "paper");
           set("unique", 1);
           set("treasure", 1);
	   set("skill", ([
		"name":	"strike",	 
		"exp_required":	300, 
                "jing_cost":    25,   
		"difficulty":	20, 
		"max_skill":	30 
	   ]));
	}
}
