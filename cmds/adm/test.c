// where.c
// 06-14-95

inherit F_CLEAN_UP;

int main(object me,string arg)
{

        object ob;
        int exp;
        int m;
        int iexp = 100;
	if( !arg || sscanf(arg, "%d", m)!=1 )
		return notify_fail("please input number\n");

        
        ob = new("/d/wuguan/npc/dizi1.c");
        exp = me->add_exp_combat(100,ob,"����");
        destruct(ob);
        write("����:"+exp+"\n");
  	if (me->is_robot(0))
		{
			if(m<4000) iexp = iexp;
			else if(m<5000) iexp = iexp * 60/100;
			else if(m<6000) iexp = iexp * 55/100;
			else if(m<7000) iexp = iexp * 50/100;
			else if(m<8000) iexp = iexp * 40/100;
			else iexp =  iexp * 30/100;	
		}
		else
		{
			if(m<6000) iexp = iexp;
			else if(m<7000) iexp = iexp * 90/100;
			else if(m<8000) iexp = iexp * 80/100;
			else if(m<9000) iexp = iexp * 70/100;
			else if(m<10000) iexp = iexp * 60/100;
			else iexp =  iexp * 50/100;	
		}
		 		write("iexp:"+iexp);     
        return 1;

}

int help(object me)
{
        write(@HELP
ָ���ʽ: where <��ҵ� ID>

���ָ����������֪���Ŀǰ���ڵ�λ��.

HELP
        );
        return 1;
}
