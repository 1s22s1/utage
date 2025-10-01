```mermaid
architecture-beta
    group vpc[VPC]
    group availabilityzone[Availibility Zone ap northeast 1a] in vpc
    group publicsubnet[Public subnet] in availabilityzone

    service ec2a(logos:aws-ec2)[EC2] in publicsubnet
```
