string *fengyi5_yanlian = ({
HIC"��ʹһ�С����Ƴ�ᶡ�����һ�����ԣ���ʱ����һƬ����ָ���Ե���ǰ����"NOR,
HIG"��ʹһ�С������������������ߣ���ָ���϶��»���һ���󻡣���ǰ��������ȥ��"NOR,
HIW"����ǰ����һ������ָ�������ƼȻ�����������������ȴͻȻָ��һת��ʹ�����׺���ա�ֱ��ǰ��!"NOR,
HIR"����ָһ����һʽ������ϸ��������������Ϣ�ػ���ǰ��!"NOR,
HIY"��һʽ��־�����Զ��������Ʈ�����ߣ��˷���������ָңҡָ��ǰ����"NOR,
HIM"�����ǰ��ʹ������ȥ�����С��������������ޣ���ָ�����ػ���ǰ����"NOR,
WHT"����Ƶ�����һʽ�����Ļ�����������ָ�Ի���Ծ�����缲�������ǰ����"NOR,
HIB"�㽣ָ΢����������һ�С��ߴ���ʤ�������йǽ�����쫷�����ǰ����"NOR,
YEL"�㽣ָ������仯������һ�С���������������������֮���£������޶�������׽����"NOR,
RED"��ͻȻ��������б��ܳ���ʹ�������ף�ڡ���ƾ�����������Ƴ�������������ʱ֮������ǰ���ռ䡣"NOR,
CYN"�����ִ�������ס�ζ�����ʯ��������ʹ�����������������������޷��жϳ��˶����С�"NOR,
MAG"�㽣�й��Ƽ�ǿ��ȴȫ�����Է�������·��ʹ��һ�С������ϸǡ����仯Ī��ع���ǰ�������ƾ���˿�������Ѱ��"NOR,
});

int fengyi5_zhuomo(object);

int fengyi5_zhuomo(object me)
{
    if((int)me->query("quest/hsjf/fengyi5_fail")>=5)
    {
         write("������Ⱳ�Ӷ��޷���ĥ͸��������ˡ�\n");
         return 1;
     }

    if((int)me->query("quest/hsjf/fy5/yanlian_time")+43200>time())
    {
         write("�����ĥ��������Ŀǰ���޷�������չ��\n");
         return 1;
     }

    if((int)me->query("quest/hsjf/fy5/yanlian_exp")+50000>(int)me->query("combat_exp"))
    {
         write("����۵�ʵս�����л���!\n");
         return 1;
     }

    if(me->query("quest/hsjf/fy5/yanlian")=="pass")
    {
         write("����������Լ���ˮƽ��ʵ���޷���ĥ�����Ľ��У�\n");
         return 1;
     }

    write(HIG"������۾���������ĥ�Ż�ɽ������ÿһ�У�ÿһʽ��������������ǰ������\n\n"+
          HIY"��˼�������������Ϊ�����Ȼ�����������ʱ���Ѹ������ں�ʹ������ʽ��\n"+
          HIY"��������ʹ����\n"NOR);

    me->start_busy(999);//��ֹplayer���߶�. by lsxk@hsbbs
    call_out("fengyi5_yanlian",3,me);
    return 1;
}

int fengyi5_yanlian(object me)
{
    int i;
    string killer_location;
    if(file_name(environment(me))!="/d/huashan/cave"
      &&file_name(environment(me))!="/u/lsxk/partyskill/newhs/quest/cave")
         return 1;

    if((int)me->query_temp("quest/huashan/fengyi5/yanlian")>7){
        if(!random(4)||me->query("quest/hsjf/fy5/yanlian")=="again"){
          write(HIC"\n�����о��ް�������������ʹ��һ���ǳɣ������νӵ������޷죬������\n"+
                     "ȱ��������ȴ���ɾ����޷��ںϽ����з����ǡ�֮�У��κ�һ�ж���������\n"+
                     "��׸֮�С���ֻ���ã����޸���ָ�㣬�������Է����⡰�з����ǡ����е�\n"+
                     "����������\n"NOR);
            me->delete_temp("fengyi5_zhuomo");
            me->delete_temp("quest/huashan/fengyi5/yanlian");
            me->set("quest/hsjf/fy5/meet_killers",1);
            me->set("quest/hsjf/fy5/yanlian","pass");
            me->set("quest/hsjf/fy5/yanlian_time",time());
            me->set("quest/hsjf/fy5/yanlian_exp",me->query("combat_exp"));

            i = random(4);
            switch(i)
            {
                 case 0 : killer_location="qlmnj";break;
                 case 1 : killer_location="zqmnj";break;
                 case 2 : killer_location="xwmnj";break;
                 default : killer_location="bhmnj";break;
             }
            me->start_busy(1);
            me->set("quest/hsjf/fy5/location",killer_location);
            log_file("quest/fengyi5", sprintf(HIG"�з�����5Quest��¼��%s(%s)�ڻ�ɽ�ض�"HIW"��ĥ"HIG"�ɹ�������%d��"NOR, me->name(1),me->query("id"), me->query("combat_exp")) );
            return 1;
        }
        else{
            write(HIR"������ƺ��е��ĵã����ܻ���ҪһЩʵս�����۾���ɡ�\n"NOR);
            me->delete_temp("fengyi5_zhuomo");
            me->delete_temp("quest/huashan/fengyi5/yanlian");
            me->set("quest/hsjf/fy5/yanlian","failed");
            me->set("quest/hsjf/fy5/yanlian_time",time());
            me->set("quest/hsjf/fy5/yanlian_exp",me->query("combat_exp"));
            me->start_busy(1);
            log_file("quest/fengyi5", sprintf(HIR"�з�����5Quest��¼��%s(%s)�ڻ�ɽ�ض�"HIW"��ĥ"HIR"ʧ�ܡ�����%d��"NOR, me->name(1),me->query("id"), me->query("combat_exp")) );
            return 1;
        }
    }
    else{
        write("\n"+fengyi5_yanlian[random(sizeof(fengyi5_yanlian))]+"\n");
        me->add_temp("quest/huashan/fengyi5/yanlian",1);
        call_out("fengyi5_yanlian",5,me);
        return 1;
    }

    return 1;
}
