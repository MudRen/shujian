//�Խ�ר�á� by lsxk@hsbbs 2007/9/26

int do_duijiang()
{
    int i, k, j;
    string strDuijiang, strReport, strReportLog, *strTemp, *strTemp2, *strReportTemp;
    object me = this_player();

    if(!present("cai piao",me)){
        me->delete("caipiao");
        me->delete("caipiao_id");
        return notify_fail("�������ƾ֤�أ�\n"NOR);
    }

    if(!query("no_buy")) return notify_fail("��û�����أ���ɶ���֣��ø�ɶ��ɶȥ����\n"NOR);

    if(!(i=sizeof(me->query("caipiao")))) return notify_fail("�㻹û���Ʊ������ʲô����һ������ȥ��\n"NOR);

    if(me->query("caipiao_id")!=This_Source){
        me->delete("caipiao");
        me->delete("caipiao_id");
        tell_object(me,"С�����ù��ڵĲ�Ʊ���Խ�����Wiz��ɵ�İ���\n"NOR);
        destruct(present("cai piao",me));
        return 1;
    }

    strDuijiang = me->query("caipiao/��"+chinese_number(i)+"��/my_caipiao");

    for(k=0;k<SIZE_OF_SOURCE/2;k++){
        if(!strTemp) strTemp = ({duijiang_char[k]+duijiang_char[k+1]});
        else strTemp  += ({duijiang_char[k*2]+duijiang_char[k*2+1]});
    }

    strTemp2 = explode(strDuijiang, "-");
    for(k=0;k<SIZE_OF_SOURCE/2;k++){
        for(j=0;j<SIZE_OF_SOURCE/2;j++){
            if(strTemp[k]==strTemp2[j]){
               me->set("caipiao_zhongjiang_list/"+strTemp[k], 1);
               me->add("caipiao_shot",me->query("caipiao_shot")+sizeof(me->query("caipiao_zhongjiang_list")));
               if(k==j) me->add("caipiao_shot",sizeof(me->query("caipiao_zhongjiang_list")));
               j = SIZE_OF_SOURCE/2;
            }
        }
    }

    strReport = HIM"������н����������Ϊ:\n"HIG;
    strReportLog = " ";
    if(me->query("caipiao_zhongjiang_list")){
        strReportTemp = keys(me->query("caipiao_zhongjiang_list"));
        for(k=0;k<sizeof(me->query("caipiao_zhongjiang_list"));k++){
            strReport += strReportTemp[k] + " ";
            strReportLog += strReportTemp[k]+" ";
        }
        tell_object(me, strReport + "\n"NOR);

        log_file("caipiao", sprintf(HIG"%s(%s)��%d�Ų�Ʊ��%s �н���ϵͳ�н��ţ�%s �н�����:%s"NOR,me->name(),me->query("id"),i,me->query("caipiao/��"+chinese_number(i)+"��/my_caipiao"),strPriKaijiang, strReportLog));
        if(me->query("caipiao/��"+chinese_number(i)+"��/huobi")=="ͨ��"){
            tell_object(me,HIY"��ϲ!�˴��н�,ʹ������"+HIW+chinese_number((int)me->query("caipiao_shot")*CREDIT_COST)+HIY+"������ͨ��!\n"NOR);
            me->add("SJ_Credit",(int)me->query("caipiao_shot")*CREDIT_COST);
        }
        if(me->query("caipiao/��"+chinese_number(i)+"��/huobi")=="�ƽ�"){
            tell_object(me,HIY"��ϲ!�˴��н�,ʹ������"+HIW+chinese_number((int)me->query("caipiao_shot")*GOLD_COST/10000)+HIY+"���ƽ�!\n"NOR);
            me->add("balance",(int)me->query("caipiao_shot")*GOLD_COST);
        }
    }
    else tell_object(me, HIR"���ź�,���Ų�Ʊ,��û�����κν�,��л���Ĳ���,ף���´��н�!\n"NOR);

    me->delete("caipiao/��"+chinese_number(i)+"��");
    me->delete("caipiao_zhongjiang_list");
    me->delete("caipiao_shot");

    if(!sizeof(me->query("caipiao"))){
        me->delete("caipiao");
        me->delete("caipiao_id");
        destruct(present("cai piao", me));
    }

    return 1;
}
