
inherit ITEM;

void create()
{
	set_name("��װ����", ({ "jingshu", "shu", "jing", "book" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ���ܾɵ���װ���顣����д���ľ�����г��޳� ˫������ �ϱ����� �Ǽٷǿ� \n");
    	set("value", 0);
		set("material", "paper");
	
	}
}
void init()
{
        add_action("do_du", "du");
        add_action("do_du", "study");
}
int do_du(string arg)
{
        object me = this_player();
        object where = environment(me);
        int neili_lost;
        if (!(arg=="jing" ||arg=="book"))
        return 0;

        if (where->query("pigging")){
                write("�㻹��ר�Ĺ���ɣ�\n");
                return 1;
        }
        if (me->is_busy()) {
                write("��������æ���ء�\n");
                return 1;
        }

        if( me->is_fighting() ) {
                write("���޷���ս����ר�������ж���֪��\n");
                return 1;
        }

        if (!id(arg)) {	
                write("��Ҫ��ʲô��\n");
                return 1;
        }
       
        if( !me->query_skill("literate", 1) ){
                write("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");
                return 1;
        }
        
        if( (int)me->query("jing") < 15 ) {
                write("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");
                return 1;
        }
	if (me->query_skill("force",1)<80){
		write("����ڹ�����û�д�ã�������������������\n");
		return 1;
	}
       if (me->query_skill("qiantian-yiyang",1)<80){
		write("�������Ǭ��һ����������򣬲���ѧϰ����������\n");
		return 1;
	}

	if (me->query_skill("qiantian-yiyang",1)<me->query_skill("kurong-changong",1)){
		write("�������Ǭ��һ����������죬�����ټ���ѧϰ����������\n");
		return 1;
	}
	if( (int)me->query("neili") < neili_lost) {
		write("�������������޷�������ô������书��\n");
                return 1;
        }
	if ((int)me->query_skill("buddhism",1)<(int)me->query_skill("kurong-changong",1))
	{
		write("��������ķ���Ϊ�������޷���������Ŀ��ٹ���\n");
		return 1;
	}
        if(me->query_skill("kurong-changong",1)>40){
                write("���Ѿ��޷��ٴӾ���������ʲô�ˡ�\n");
                return 1;
        }
	neili_lost=(int)(me->query_skill("kurong-changong",1)/10);
        me->receive_damage("jing", 15);
	me->set("neili",(int)me->query("neili")-neili_lost);
	me->improve_skill("kurong-changong", (int)me->query_skill("literate", 1)/3+1);
	message("vision", me->name() + "����һ����������ĬĬ���š�\n", environment(me), me);
        write("��Ĭ�о��飬�����ĵá�\n");
	return 1;
}
