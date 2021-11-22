import java.util.Scanner;


public class Newspaper_saler_problem {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
	//	String newspaper_type="";
		String more="";
	 
		
		float buy_cost=33,sell_price=50;
		int demand,total_newspaper,day=1;
		float cost_of_newspaper,lost_profit,salvage_from_sale,revenue_from_sale,profit,total_profit=0;
		Scanner sc=new Scanner(System.in);
		do{
			
		
		//System.out.println("Enter the newspaper type ");
		//newspaper_type=sc.next();
		System.out.println(" Enter the total newspaper for day "+day);
		total_newspaper=sc.nextInt();
		System.out.println(" Enter the demand of newspaper for "+day);
		demand=sc.nextInt();
		if(demand>total_newspaper)
		{
			revenue_from_sale=total_newspaper*sell_price;
			lost_profit=(demand-total_newspaper)*(sell_price-buy_cost);
			salvage_from_sale=0;
		}
		else
		{
				revenue_from_sale=demand*sell_price;
				lost_profit=0;
				salvage_from_sale=5*(total_newspaper-demand);
		}
		cost_of_newspaper=buy_cost*total_newspaper;
		profit=revenue_from_sale-cost_of_newspaper-lost_profit+salvage_from_sale;
		
		System.out.println("Day "+day+" Demand = "+demand+" Revenue = "+(revenue_from_sale/100)+"$ Cost = "+(cost_of_newspaper/100)+"$ Lost profit from excess demand = "+(lost_profit/100)+"$ Salvage from scrapt paper = " +(salvage_from_sale/100)+"$");
		System.out.println("Day "+day+" Profit = "+(profit/100)+"$");
		System.out.println("Do you want add more day ");
		more=sc.next();
		total_profit=total_profit+profit;
		day=day+1;
		}while(more.equals("yes"));
		System.out.println("After "+(day-1)+" days total profit : "+(total_profit/100)+"$");
		sc.close();

	}

}
