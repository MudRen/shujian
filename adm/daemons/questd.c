//Create by lsxk@hsbbs 2007/8/20
//����Quest�����ж�,�������š�grin
//Update by lsxk �����츳Ӱ��Ч����  2008/4/16
/*
ʹ�÷������ܣ�
1����������á����������򷵻�1�����򷵻�0.
QUEST_D->questing(����,�Ѷ�ϵ��,vip�Ѷȵ���ϵ��,����Դ)
����Դ���ó������ĸ���ֵȥ���м��㡣��4��ѡ��
"KAR"-----ֻѡ��ǰ����ĸ�Եȥ���㡣
"PUR"-----ֻѡ��ǰ����Ĵ���ȥ���㡣
"BOTH"----ѡ��ǰ����ĸ�Ե�봾�ӵĺ�ȥ���㡣
  1  -----ѡ��ֱ���ò����еġ��Ѷ�ϵ����ȥ���㡣
���ѡ��"KAR","PUR","BOTH",���㹫ʽΪ��
random(����Դ)>�Ѷ�ϵ��?:1:0
������ң���:random(����Դ)>(�Ѷ�ϵ��-vip�Ѷȵ���ϵ��)?:1:0
�������Դ���ݵ�����ֵ1������㹫ʽΪ��
������ң���!random(�Ѷ�ϵ��-vip�Ѷȵ���ϵ��)?:1:0
2����������趨:
�ܹ�����������ң�
deny_quest_player----ֻҪ����������id,���ص�ֵ����0,��������
���жϡ�
vip_quest_player-----�����������ˣ��Ż��á�vip�Ѷȵ���ϵ����
ȥ���Ѷȵ��ڡ�
���ַ�ʽ�趨��
A:��/adm/daemons/questd.c���vip_quest_player���������player
��id, ����deny_quest_player���������id. update���¼���������Ч.
B:�ú���������ӣ�
QUEST_D->add_quest_player(���"DENY")--��������ʱ��ӵ�deny����
QUEST_D->add_quest_player(���"VIP")---��������ʱ��ӵ�vip����
QUEST_D->delete_quest_player(���"DENY")--��������ʱ��deny����ɾ��
QUEST_D->delete_quest_player(���"VIP")--��������ʱ��vip����ɾ��
*/

private int calc_quest(object, int, int, int);

//�ܾ���quest����б��ͷ����⵷�ҵ��ˡ�grin
string *deny_quest_player = ({ });

//string *deny_quest_player = ({"zmud",});

//�����б��е�player�����һ����quest�ɹ��ʣ������ɴ��ݵĲ���������
string *vip_quest_player = ({"zmud", });

//��Ӹ�player����Ӧ�������С���arg���Ƶ�deny����vip.
void add_quest_player(object ob, string arg)
{
    int i;
    if(arg=="DENY"){
        for(i=0;i<sizeof(deny_quest_player);i++)
            if(ob->query("id")==deny_quest_player[i])
                return;

        deny_quest_player += ({ob->query("id")});
    }
    else{
        for(i=0;i<sizeof(vip_quest_player);i++)
            if(ob->query("id")==vip_quest_player[i])
                return;

        vip_quest_player += ({ob->query("id")});
    }
    return;
}

//��������ɾ����player����arg���Ƶ�deny����vip.
void delete_quest_player(object ob, string arg)
{
    if(arg=="DENY"){
        deny_quest_player -= ({ob->query("id")});
    }
    else{
        vip_quest_player -= ({ob->query("id")});
    }
    return;
}

//�ⲿ���ýӿ�
int questing(object me, int level, int rlvl, string arg)
{
    int i, mboth;

        for(i=0;i<sizeof(deny_quest_player);i++)
            if(me->query("id")==deny_quest_player[i])
                return 0;

  /*����level���Ѷȵ���,rlvl�����vip���Ѷ�΢��,levelΪ0�򷵻ؼ�ֵ,Ϊ
    1�򷵻���ֵ,���������򷵻ء�1/���֡��ĸ���Ϊ��ֵ,��������,�򷵻ؼ�.*/
    if(level<=0) return 0;
    if(level==1) return 1;
//    if(typeof(level)!=2) return 0;
    if(!objectp(me)) return 0;

       //tagΪ�����ֲ������м���ı�־��
        if(arg=="KAR")
            return calc_quest(me,me->query("kar"),level,rlvl);
        else if (arg=="PUR")
            return calc_quest(me,me->query("pur"),level,rlvl);
        else if (arg=="BOTH"){
            mboth = (int)me->query("kar")+(int)me->query("pur");
            return calc_quest(me,mboth,level,rlvl);
        }
        else
            return calc_quest(me,0,level,rlvl);

    return 0;
}

private int calc_quest(object me, int i, int level, int rlvl)
{
    int j;

  //���i��0����ֻ��level�����жϡ�
    if(!i){
        //�츳��̽�����ˡ�Ӱ��Ч����  by lsxk@hsbbs 2008/3/16
        if(me->query("relife/quest/txqr"))
            level -= level * (int)me->query("relife/quest/txqr",1) / 100;
        
        if(level <= rlvl)  level = rlvl + 1;

        for(j=0;j<sizeof(vip_quest_player);j++)
            if(me->query("id")==vip_quest_player[j])
            {
                //�츳��̽��ר�ҡ�Ӱ��Ч����  by lsxk@hsbbs 2008/3/16
                if(me->query("relife/quest/txzj") && (random(100) < (int)me->query("relife/quest/txzj",1) * 2)){
                    if(!(!random(level-rlvl)?1:0))
                        return !random(level-rlvl)?1:0;
                    else return 1;
                    }
                return !random(level-rlvl)?1:0;
            }
        //�츳��̽��ר�ҡ�Ӱ��Ч����  by lsxk@hsbbs 2008/3/16
        if(me->query("relife/quest/txzj") && (random(100) < (int)me->query("relife/quest/txzj",1) * 2)){
            if(!(!random(level)?1:0))
                return !random(level)?1:0;
            else return 1;
            }
        return !random(level)?1:0;
    }
  //���i��Ϊ0,���ж�random(i)>level���ŷ���1
    else{
        //�츳��̽�����ˡ�Ӱ��Ч����  by lsxk@hsbbs 2008/3/16
        if(me->query("relife/quest/txqr"))
            level -= i * (int)me->query("relife/quest/txqr",1) / 100;

        if(level <= rlvl)  level = rlvl + 1;

        for(j=0;j<sizeof(vip_quest_player);j++)
            if(me->query("id")==vip_quest_player[j])
            {
                //�츳��̽��ר�ҡ�Ӱ��Ч����  by lsxk@hsbbs 2008/3/16
                if(me->query("relife/quest/txzj") && (random(100) < (int)me->query("relife/quest/txzj",1) * 2)){
                if(!((random(i)>(level-rlvl))?1:0))
                    return (random(i)>(level-rlvl))?1:0;
                else return 1;
                }
                return (random(i)>(level-rlvl))?1:0;
            }
            //�츳��̽��ר�ҡ�Ӱ��Ч����  by lsxk@hsbbs 2008/3/16
            if(me->query("relife/quest/txzj") && (random(100) < (int)me->query("relife/quest/txzj",1) * 2)){
                if(!((random(i)>level)?1:0))
                    return (random(i)>level)?1:0;
                else return 1;
                }
        return (random(i)>level)?1:0;
    }
}
